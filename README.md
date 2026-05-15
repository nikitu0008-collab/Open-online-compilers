# Online Compiler Finder

[![Language](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://en.cppreference.com/w/cpp/23)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![curl](https://img.shields.io/badge/curl-libcurl-orange)](https://curl.se/)

**Never miss your laptop again.**  
This tool scans a curated list of online compilers/IDEs for your chosen language, checks which one is alive, and opens it in your browser – instantly.

## Why?

- You forgot your laptop / don’t have it at hand.
- Your local compiler is broken or not installed.
- You just want a quick online environment to test a snippet.

## Supported languages (12)

| Language     | Status |
|--------------|--------|
| C++          | ✅     |
| Python       | ✅     |
| JavaScript   | ✅     |
| Rust         | ✅     |
| Go           | ✅     |
| PHP          | ✅     |
| TypeScript   | ✅     |
| Swift        | ✅     |
| Kotlin       | ✅     |
| Ruby         | ✅     |
| Java         | ✅     |
| C#           | ✅     |

> Each language has 5–10 popular online compilers (jdoodle, onlinegdb, replit, etc.)

## How it works

1. You select a language from the menu.
2. The program sends a **HEAD request** (with libcurl) to each compiler URL.
3. The first site that responds with HTTP `2xx` or `3xx` is considered alive.
4. Your default browser opens that website.

## Requirements

- **C++23 compiler** (GCC 13+, Clang 15+, or MSVC 2022 17.5+)
- **libcurl** (development package)

## Installation & build

### Windows (MSYS2 – recommended)
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-curl
g++ -std=c++23 online_compiler_finder.cpp -o ocf.exe -lcurl
Linux (Debian/Ubuntu)
bash
sudo apt install libcurl4-openssl-dev g++
g++ -std=c++23 online_compiler_finder.cpp -o ocf -lcurl
macOS (Homebrew)
bash
brew install curl
g++ -std=c++23 online_compiler_finder.cpp -o ocf -lcurl
Usage
bash
./ocf          # on Linux/macOS
ocf.exe        # on Windows
Follow the menu, pick a number, and the program will find a working online compiler.

Example output:

text
====================================
Select programming language:
1. C++
2. Python
...
>_: 1

Checking: https://www.jdoodle.com/c-online-compiler
[✅] Open...
(Your browser opens jdoodle)
Adding more compilers
Just edit the vectors inside main() – each language has its own std::vector<std::string>.

Known limitations
Some sites may block HEAD requests (rare). The program will simply skip them.

Firewall or network issues might affect reachability.

License
MIT – feel free to use, modify, and share.

Contributing
Pull requests with additional compilers or languages are welcome!
