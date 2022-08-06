#include <iostream>
#include <memory>
#include <string>

#include "include/md4c/src/md4c.h"
#include "include/md4c/src/md4c-html.h"
#include "include/md4c/src/entity.h"

struct post {
    std::string post_html;
};

int main() {
    std::string s("# Hello World\n\nThis is a simple post.\n\n");

    post* p = new post();

    md_html(s.c_str(), s.size(), [](const MD_CHAR* html, MD_SIZE html_size, void* userdata) {
        post* p = (post*)userdata;
        p->post_html.append((const char*)html, html_size);
    }, p, 0, 0);

    std::cout << p->post_html << std::endl;
    std::cout << "=== Run complete ===" << std::endl;
    return 0;
}