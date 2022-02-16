#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

struct brick_names_struct {
    std::vector<std::pair<std::string, std::string>> a;
    std::vector<std::pair<std::string, std::string>> b;
    
};

bool sortbysec(const std::pair<std::string, std::string>& a,
    const std::pair<std::string, std::string>& b)
{
    return (a.second < b.second);
}

brick_names_struct get_all_bricks(std::string path)
{
    path.erase(std::remove_if(path.begin(), path.end(), ::isspace), path.end());
    brick_names_struct brick_names;
    std::ifstream infile(path);
    if (!infile.good()) throw std::invalid_argument("Error: File not found");
    std::string line;
    while (std::getline(infile, line)) {
        const size_t pos = line.find(",");
        const std::string side1 = line.substr(0, pos);
        const std::string side2 = line.substr(pos + 1);
        brick_names.a.push_back({ side1, side2});
    }
    infile.close();
    brick_names.b = brick_names.a;
    std::sort(brick_names.b.begin(), brick_names.b.end());
    std::sort(brick_names.a.begin(), brick_names.a.end(), sortbysec);
    return brick_names;
}

int main()
{
    brick_names_struct bricks = get_all_bricks("Great_Wall_Problem-test_data\\20\\input-pairs-20.txt");
    int n = bricks.a.size();
    std::vector<std::pair<std::string, std::string>> c;
    std::vector<std::pair<std::string, std::string>> p;
    int a_point = 0;
    int b_point = 0;
    for (int x = 0; x < int(bricks.a.size()); x++) {
        std::cout << bricks.a[a_point].first << "\t" << bricks.b[b_point].second << std::endl;
        if (bricks.a[a_point].second == bricks.b[b_point].first) {
            c.push_back({ bricks.a[a_point].first, bricks.b[b_point].second });
            a_point += 1;
            b_point += 1;
        }
        else if (bricks.a[a_point].second < bricks.b[b_point].first) {
            p.push_back({ bricks.a[a_point].first, std::to_string(n - 1)});
            p.push_back({ bricks.a[a_point].second, std::to_string(n) });
            a_point += 1;
            std::cout << "end or start found" << std::endl;
        }
        else if (bricks.a[a_point].second > bricks.b[b_point].first) {
            b_point += 1;
            std::cout << "end or start found" << std::endl;
        }
    }


    /*
    for (auto x : bricks.a) {
        std::cout << x.first << "\t" << x.second << std::endl;
    }

    std::cout << "\nsorted by second: " << std::endl;
    for (auto x : bricks.b) {
        std::cout << x.first << "\t" << x.second << std::endl;
    }
    */
}