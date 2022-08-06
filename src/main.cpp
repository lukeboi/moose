#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include "include/md4c/src/md4c.h"
#include "include/md4c/src/md4c-html.h"
#include "include/md4c/src/entity.h"

struct post {
    std::string markdown_filename;
    std::string post_html;
};

std::string readfile(const std::string& filename) {
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    return content;
}

int main(int argc, char * argv[]) {
    std::string filename = "costa.md";
    std::string s = readfile(filename);

    post* p = new post();

    md_html(s.c_str(), s.size(), [](const MD_CHAR* html, MD_SIZE html_size, void* data) {
        post* p = (post*)data;
        p->post_html.append((const char*)html, html_size);
    }, p, 0, 0);

    std::cout << p->post_html << std::endl;
    std::cout << "=== Run complete ===" << std::endl;
    return 0;
}