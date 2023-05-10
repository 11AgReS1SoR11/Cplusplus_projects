#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void Fill(std::vector<std::string>& a, std::string& s) {
    std::istringstream str(s); // преобразую строку в поток
    std::istream_iterator<std::string> eos; // end-of-stream iterator
    std::istream_iterator<std::string> it(str);
    while (it != eos) {
        a.push_back(*it);
        it++;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::cout << "¬ведите название файла и длину строки через пробел" << std::endl;
    int n; 
    std::string filename;
    std::cin >> filename >> n;
	
    std::string s;
    std::vector<std::string> words;
    std::ifstream in(filename); // окрываем файл дл€ чтени€
    if (in.is_open())
    {
        while (std::getline(in, s))
        {
            Fill(words, s);
        }
    }
    in.close();


    std::ofstream out(filename);
    if (out.is_open())
    {
        int len = n;
        std::string tmp = "";
        for (auto& w : words) {
            if (w.size() > n) {
                tmp += w.substr(0, len);
                out << tmp << std::endl;
                while (len + n < w.size()) {
                    out << w.substr(len, n) << std::endl;
                    len += n;
                }
                tmp = w.substr(len) + ' ';
                len = n - (w.size() - len) - 1;
            }
            else if (w.size() <= len) {
                tmp += w + ' ';
                len -= w.size() + 1;
            }
            else {
                for (int i = 0; i < (len + 1) / 2; i++) out << ' ';
                out << tmp;
                for (int i = (len + 1) / 2; i < len; i++) out << ' ';
                out << std::endl;
                tmp = w + ' ';
                len = n - (w.size() + 1); 
            }
            if (len < 0) len = 0;
        }
        for (int i = 0; i < (len + 1) / 2; i++) out << ' ';
        out << tmp;
        for (int i = (len + 1) / 2; i < len; i++) out << ' ';
        out << std::endl;
    }
    out.close();
	return 0;
}