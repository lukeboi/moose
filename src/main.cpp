#include <iostream>
#include <memory>
#include <string>

#include "include/md4c/src/md4c.h"

int main() {
    std::string s("# Hello World");
    // config is optional
//    std::shared_ptr<maddy::ParserConfig> config = std::make_shared<maddy::ParserConfig>();
//    config->isEmphasizedParserEnabled = true; // default
//    config->isHTMLWrappedInParagraph = true; // default
//
//    std::shared_ptr<maddy::Parser> parser = std::make_shared<maddy::Parser>(config);
//    std::string htmlOutput = parser->Parse(markdownInput);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
