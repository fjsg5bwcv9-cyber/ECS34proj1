#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {
    ssize_t n = str.length();

    if (end == 0) end = n;

    if (start < 0) start = n + start;
    if (end < 0)   end   = n + end;

    if (end > n)   end   = n;

    if (start >= end) return "Error";

    return str.substr(start, end - start);
}


std::string Capitalize(const std::string &str) noexcept{
    if (str.empty()) return "";
    std::string capi = str;
    if (capi[0]>='a' && capi[0]<='z'){
        capi[0] = capi[0]-'a'+'A';
    }
    for (size_t i = 1; i < capi.length(); ++i) {
        if (capi[i] >= 'A' && capi[i] <= 'Z') {
            capi[i] = capi[i] - 'A' + 'a';
        }
    }

    return capi;
}

std::string Upper(const std::string &str) noexcept{
    if (str.empty()) return "";
    std::string upp = str;
    for (size_t i = 0; i < upp.length(); ++i) {
        if (upp[i] >= 'a' && upp[i] <= 'z') {
            upp[i] = upp[i] - 'a' + 'A';
        }
    }
    return upp;
}

std::string Lower(const std::string &str) noexcept{
    if (str.empty()) return "";
    std::string low = str;
    for (size_t i=0; i < low.length(); ++i){
        if (low[i]>='A' && low[i]<='Z'){
            low[i]=low[i]+'a'-'A';
        }
    }
    return low;
}

std::string LStrip(const std::string &str) noexcept{
    size_t i = 0;
    while (i < str.length() && (str[i] == ' ')){
        ++i;
    }
    return str.substr(i);
}

std::string RStrip(const std::string &str) noexcept{
    if (str.empty()) return "";

    size_t i = str.length();
    while (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n')) {
        --i;
    }
    return str.substr(0, i);
}

std::string Strip(const std::string &str) noexcept{
    return RStrip(LStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept {
    if (width <= (int)str.length()) return str;

    int pad = width - (int)str.length();
    int left = pad / 2;
    int right = pad - left;

    return std::string(left, fill) + str + std::string(right, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept {
    if (width <= (int)str.length()) return str;

    int pad = width - (int)str.length();
    return str + std::string(pad, fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept {
    if (width <= (int)str.length()) return str;

    int pad = width - (int)str.length();
    return std::string(pad, fill) + str;
}


std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string out;
    size_t pos = 0;

    while (true) {
        size_t found = str.find(old, pos);
        if (found == std::string::npos) {
            out += str.substr(pos);
            break;
        }
        out += str.substr(pos, found - pos);
        out += rep;
        pos = found + old.length();
    }

    return out;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> result;//The length of the string is unknown

    size_t start = 0;
    size_t pos;

    while ((pos = str.find(splt, start)) != std::string::npos) {
        result.push_back(str.substr(start, pos - start));
        start = pos + splt.length();
    }

    result.push_back(str.substr(start));

    return result;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string out = vect[0];
    for (size_t i = 1; i < vect.size(); ++i) {
        out += str;
        out += vect[i];
    }
    return out;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string out;
    int col = 0;

    for (char c : str) {
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
    return out;
}


int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    auto norm = [&](char c) -> char {
    if (!ignorecase) return c;
    if (c >= 'A' && c <= 'Z') return char(c - 'A' + 'a');
    return c;
};

    int n = (int)left.size();
    int m = (int)right.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (norm(left[i - 1]) == norm(right[j - 1])) ? 0 : 1;

            int del = dp[i - 1][j] + 1;
            int ins = dp[i][j - 1] + 1;
            int sub = dp[i - 1][j - 1] + cost;

            int best = del;
            if (ins < best) best = ins;
            if (sub < best) best = sub;

            dp[i][j] = best;
        }
    }

    return dp[n][m];

}
}

