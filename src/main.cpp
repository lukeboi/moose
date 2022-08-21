#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <filesystem>

#include "include/md4c/src/md4c.h"
#include "include/md4c/src/md4c-html.h"
#include "include/md4c/src/entity.h"

struct post {
    std::string md_filename;
    std::string html_filename;
    std::string title;
    std::string post_md;
    std::string post_html;
};

// basic file reading functions
std::string readfile(const std::string& filename) {
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void writefile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

std::tuple<std::string, std::string> extract_first_line(const std::string& content) {
    std::string first_line;
    std::string rest_of_file;
    std::stringstream ss(content);
    std::getline(ss, first_line);
    std::getline(ss, rest_of_file);
    return std::make_tuple(first_line, rest_of_file);
}

int main(int argc, char * argv[]) {
    std::string md_path = "./md/";

    for (const auto & entry : std::filesystem::directory_iterator(md_path)) {
        std::cout << std::endl << "Parsing file:" << entry.path() << std::endl;

        post* p = new post();
        p->md_filename = entry.path().string();
        std::string md_file_raw = readfile(p->md_filename);

        // get first line of the markdown file (html template path)
//        auto found = md_file_raw.find("\n");
//        if (found != std::string::npos)
//            std::cout << "First line is: " << md_file_raw.substr(0, found) << std::endl;
//        auto [ html_filename, remaining ] = extract_first_line(md_file_raw);

        // now that we have extracted our metadata, write the markdown to the right field
//        p->post_md = md_file_raw.substr(found + 1, md_file_raw.length() - found);

        // TODO IMPLEMENT THIS
        std::istringstream input(md_file_raw);
        int line_num = 0;
        for (std::string line; std::getline(input, line);) {
            line_num++;
            std::cout << line_num << " " << line << std::endl;

            if (line_num == 1) { // post title
                p->title = line;
            }
            else if (line_num == 2) { // post html filename
                p->html_filename = line.substr(0, line.find("\n"));
                std::cout << " post html filename ^^^ " << line << std::endl;
            }
        }

        // print a sampling of the markdown
        std::cout << "Sample of the markdown: " << p->post_md.substr(0, 50) << std::endl;

        // do html conversion, put it in post struct
        md_html(p->post_md.c_str(), p->post_md.size(), [](const MD_CHAR* html, MD_SIZE html_size, void* data) {
            post* p = (post*)data;
            p->post_html.append((const char*)html, html_size);
        }, p, 0, 0);

        // write the html to a file
        writefile(p->html_filename, p->post_html);
        std::cout << "HTML written to: " << p->html_filename << std::endl;
    }
    std::cout << "=== Run complete ===" << std::endl;
    return 0;
}