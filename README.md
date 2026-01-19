# ECS34proj1
Yueqiang Hu (923469948)
## Project Status
This the current status of the project is finished
## Generative AI Use
I used ChatGPT for Prompt 1:std::vector<std::string> result;
I used ChatGPT for prompt 2:for (char c : str) {
        if (c == '\t') {
            int spaces = tabsize - (col % tabsize);
            out.append(spaces, ' ');
            col += spaces;
        } else {
            out.push_back(c);
            col += 1;
            if (c == '\n') col = 0;
        }
    }
I used ChatGPT for prompt 3:auto norm = [&](char c) -> char {
    if (!ignorecase) return c;
    if (c >= 'A' && c <= 'Z') return char(c - 'A' + 'a'); //This checks if the character is an uppercase letter
    return c;
};
### Prompt 1
How to declare an unknown length string and store split?
### Response 1
ChatGPT explained how to iterate over characters in a C++ string using a range-based for loop and showed that a std::vector<std::string> can be used to store multiple string elements.
### Prompt 2
How to implement tab expansion in C++
### Response 2
ChatGPT provided a code example demonstrating how to expand tab characters (\t) into the correct number of spaces based on a given tab size and the current column position while iterating through a string.
### Prompt 3
How to normalize characters for case-insensitive comparison (used for ignorecase in EditDistance).
### Response 3
ChatGPT showed how to normalize characters for case-insensitive comparison by converting uppercase letters to lowercase using a helper function (norm) controlled by an ignorecase flag.
