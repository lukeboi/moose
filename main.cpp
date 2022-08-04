#include <iostream>
#include <memory>
#include <string>

#include "maddy/parser.h"

int main() {
    // config is optional
    std::shared_ptr<maddy::ParserConfig> config = std::make_shared<maddy::ParserConfig>();
    config->isEmphasizedParserEnabled = true; // default
    config->isHTMLWrappedInParagraph = true; // default

    std::shared_ptr<maddy::Parser> parser = std::make_shared<maddy::Parser>(config);
    std::string htmlOutput = parser->Parse(markdownInput);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
