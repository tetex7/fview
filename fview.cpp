/*
 * Copyright (C) 2025  Tete
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "argh.h"

typedef bool FLAG;

std::vector<std::string> get_lines(const std::string& path, const FLAG& use_cin)
{
    std::vector<std::string> lines;

    if (use_cin)
    {
        std::string line;
        while (std::getline(std::cin, line)) {
            lines.push_back(line);
        }
    }
    else
    {
        std::ifstream file = std::ifstream(path);
        //std::cout << da;
        std::string line;


        while (std::getline(file, line)) {
            lines.push_back(line);
        }
    }

    return lines;
}

#define REP_BUG_TEXT "Copyright (C) 2024  Tete.\nFor Docs and bug reporting\nplease see: <https://github.com/tetex7/fview>."
void help(int ecode = 0)
{
    std::cout << "Usage: fview [options] [PATH_TO_FILE]\n";
    std::cout << "FVIEW HELP:\n"
    << "--no-head, -n       : dons't print \"START/END VIEW\" msg\n"
    << "--help,    -h       : you'r reading it lol\n";

    std::cout << "\n\n";
    std::cout << FV_VER << '\n';
    std::cout << REP_BUG_TEXT << '\n';
    exit(ecode);
}

int main(const int argc, const char** argv)
{
    FLAG SE_WAR = 1;
    auto cmdl = argh::parser(argc, argv);

    if (cmdl[{"-h", "--help"}])
        help();

    if (cmdl[{"-n", "--no-head"}])
        SE_WAR = 0;

    FLAG use_cin = 0;
    std::string file_path;

    if (!isatty(STDIN_FILENO))
    {
        use_cin = 1;
    }
    else if (!argc)
    {
        help(1);
    }

    if (argc > 1)
    {
        file_path = cmdl.pos_args()[cmdl.size() - 1];
    }
    else if (!use_cin)
    {
        help(1);
    }

    if(!std::filesystem::exists(file_path) && !use_cin)
    {
        std::cout << file_path << " dosn't exists\n";
        help(1);
    }

    std::vector<std::string> lines = get_lines(file_path, use_cin);
    if (SE_WAR)
        std::cout << "START OF VIEW:\n";

    for (size_t i = 0; i < lines.size(); i++)
    {
        if (i < 9)
        {
            std::cout << i+1 << "   | " << lines[i] << '\n';
        }
        else if (i < 99)
        {
            std::cout << i+1 << "  | " << lines[i] << '\n';
        }
        else if (i < 999)
        {
            std::cout << i+1 << " | " << lines[i] << '\n';
        }
        else
        {
            std::cout << "BFN" << " | " << lines[i] << '\n';
        }
    }
    if(SE_WAR)
        std::cout << "END OF VIEW\n";
    return 0;
}