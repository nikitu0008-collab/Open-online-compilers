#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>

#ifdef _WIN32
    #include <windows.h>
#endif

#include <curl/curl.h>

static auto openURL(const std::string& url) -> void {
    #ifdef _WIN32
        ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
    #elif __linux__
        system(("xdg-open " + url).c_str());
    #elif __APPLE__
        system(("open " + url).c_str());
    #endif
}

static auto WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) -> size_t {
    (void)contents; (void)userp;
    return size * nmemb;
}

static auto isSingleSiteAvailable(const std::string& url) -> bool {
    CURL* curl = curl_easy_init();
    if (!curl) return false;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    CURLcode res = curl_easy_perform(curl);
    long http_code = 0;
    bool available = false;

    if (res == CURLE_OK) {
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        available = (http_code >= 200 && http_code < 400);
    }

    curl_easy_cleanup(curl);
    return available;
}

static auto isSiteAvailable(const std::vector<std::string>& urls) -> bool {
    for (const auto& url : urls) {
        std::cout << "Checking: " << url << std::endl;
        if (isSingleSiteAvailable(url)) {
            std::cout << "[✅] Open..." << std::endl;
            openURL(url);
            return true;
        } else {
            std::cout << "[❌] Not opening..." << std::endl;
        }
    }
    std::cout << "[⚠️] No working compiler found." << std::endl;
    return false;
}

auto main() -> int {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    const std::vector<std::string> StorageCPP = {
        "https://www.jdoodle.com/c-online-compiler",
        "https://www.tutorialspoint.com/compile_cpp_online.php",
        "https://www.onlinegdb.com/online_cpp_compiler",
        "https://cpp.sh/",
        "https://www.programiz.com/cpp-programming/online-compiler/",
        "https://replit.com/languages/cpp",
        "https://godbolt.org/",
        "https://wandbox.org/",
        "https://coliru.stacked-crooked.com/"
    };

    const std::vector<std::string> StoragePython = {
        "https://www.onlinegdb.com/online_python_compiler",
        "https://replit.com/languages/python3",
        "https://www.programiz.com/python-programming/online-compiler/",
        "https://www.jdoodle.com/python3-programming-online",
        "https://ideone.com/",
        "https://trinket.io/python3",
        "https://www.python.org/shell/",
        "https://colab.research.google.com/notebooks/intro.ipynb"
    };

    const std::vector<std::string> StorageJavaScript = {
        "https://www.onlinegdb.com/online_javascript_compiler",
        "https://jsfiddle.net/",
        "https://codepen.io/pen/",
        "https://replit.com/languages/nodejs",
        "https://www.programiz.com/javascript/online-compiler/",
        "https://www.jdoodle.com/javascript-online-editor",
        "https://code.sololearn.com/W3uJi9A22d17/?ref=app"
    };

    const std::vector<std::string> StorageRust = {
        "https://play.rust-lang.org/",
        "https://replit.com/languages/rust",
        "https://www.onlinegdb.com/online_rust_compiler",
        "https://www.jdoodle.com/rust-online-compiler",
        "https://code.sololearn.com/cFv3k6T3T6D2/?ref=app",
        "https://wandbox.org/",
        "https://godbolt.org/"
    };

    const std::vector<std::string> StorageGo = {
        "https://go.dev/play/",
        "https://replit.com/languages/go",
        "https://www.onlinegdb.com/online_go_compiler",
        "https://www.jdoodle.com/go-online-compiler",
        "https://onecompiler.com/go",
        "https://play.golang.org/"
    };

    const std::vector<std::string> StoragePHP = {
        "https://www.onlinegdb.com/online_php_compiler",
        "https://replit.com/languages/php",
        "https://www.jdoodle.com/php-online-editor",
        "https://ideone.com/",
        "https://onecompiler.com/php",
        "https://www.programiz.com/php/online-compiler/"
    };

    const std::vector<std::string> StorageTypeScript = {
        "https://www.typescriptlang.org/play/",
        "https://replit.com/languages/typescript",
        "https://codesandbox.io/s/typescript-playground",
        "https://www.jdoodle.com/typescript-online-compiler",
        "https://onecompiler.com/typescript"
    };

    const std::vector<std::string> StorageSwift = {
        "https://swiftfiddle.com/",
        "https://replit.com/languages/swift",
        "https://www.jdoodle.com/swift-online-compiler",
        "https://online.swiftplayground.run/",
        "https://code.sololearn.com/cUkI2D2k3P2D/?ref=app"
    };

    const std::vector<std::string> StorageKotlin = {
        "https://play.kotlinlang.org/",
        "https://replit.com/languages/kotlin",
        "https://www.jdoodle.com/compile-kotlin-online",
        "https://onecompiler.com/kotlin",
        "https://ideone.com/"
    };

    const std::vector<std::string> StorageRuby = {
        "https://replit.com/languages/ruby",
        "https://www.jdoodle.com/ruby-online-compiler",
        "https://www.onlinegdb.com/online_ruby_compiler",
        "https://ideone.com/",
        "https://onecompiler.com/ruby"
    };

    const std::vector<std::string> StorageJava = {
        "https://www.jdoodle.com/online-java-compiler",
        "https://www.tutorialspoint.com/compile_java_online.php",
        "https://www.compilejava.net/",
        "https://www.onlinegdb.com/online_java_compiler",
        "https://www.programiz.com/java-programming/online-compiler/",
        "https://replit.com/languages/java",
        "https://rextester.com/l/java_online_compiler"
    };

    const std::vector<std::string> StorageCS = {
        "https://www.jdoodle.com/online-csharp-compiler",
        "https://www.tutorialspoint.com/compile_csharp_online.php",
        "https://dotnetfiddle.net/",
        "https://replit.com/languages/csharp",
        "https://www.onlinegdb.com/online_csharp_compiler",
        "https://www.programiz.com/csharp-programming/online-compiler/"
    };

    int answer = 0;
    while (answer < 1 || answer > 12) {
        std::cout << "\n====================================\n"
                     "Select programming language:\n"
                     "1. C++\n"
                     "2. Python\n"
                     "3. JavaScript\n"
                     "4. Rust\n"
                     "5. Go\n"
                     "6. PHP\n"
                     "7. TypeScript\n"
                     "8. Swift\n"
                     "9. Kotlin\n"
                     "10. Ruby\n"
                     "11. Java\n"
                     "12. C#\n"
                     "====================================\n"
                     ">_: ";
        std::cin >> answer;

        if (answer < 1 || answer > 12) {
            std::cout << "=== ERROR: invalid choice ===" << std::endl;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
    }

    switch (answer) {
        case 1:  isSiteAvailable(StorageCPP); break;
        case 2:  isSiteAvailable(StoragePython); break;
        case 3:  isSiteAvailable(StorageJavaScript); break;
        case 4:  isSiteAvailable(StorageRust); break;
        case 5:  isSiteAvailable(StorageGo); break;
        case 6:  isSiteAvailable(StoragePHP); break;
        case 7:  isSiteAvailable(StorageTypeScript); break;
        case 8:  isSiteAvailable(StorageSwift); break;
        case 9:  isSiteAvailable(StorageKotlin); break;
        case 10: isSiteAvailable(StorageRuby); break;
        case 11: isSiteAvailable(StorageJava); break;
        case 12: isSiteAvailable(StorageCS); break;
        default: __builtin_unreachable(); // or break;
    }

    curl_global_cleanup();
    return EXIT_SUCCESS;
}