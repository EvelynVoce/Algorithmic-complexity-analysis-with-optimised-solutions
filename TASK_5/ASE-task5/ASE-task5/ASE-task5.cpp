#include "ASE-task5.h"

struct brick_names_struct {
    std::list<std::pair<std::string, std::string>> a;
    std::list<std::pair<std::string, std::string>> b;
};

bool sortbysec(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
    return (a.second < b.second);
}
bool sortbysecInt(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
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
    brick_names.b.sort();
    brick_names.a.sort(sortbysec);
    return brick_names;
}

std::list<std::string> get_results(const std::string path) {
    // std::string path = "Great_Wall_Problem-test_data\\NeilExample.txt";
    brick_names_struct bricks = get_all_bricks(path);
    std::list<std::pair<std::string, std::string>>::iterator a_point = bricks.a.begin();
    std::list<std::pair<std::string, std::string>>::iterator b_point = bricks.b.begin();
    std::list<std::pair<std::string, std::string>> c;
    std::list<std::pair<std::string, int>> p;

    const int n = int(bricks.a.size());
    while (a_point != bricks.a.end()) {
        if (a_point->second == b_point->first) {
            c.push_back({ a_point->first, b_point->second });
            std::advance(a_point, 1);
            std::advance(b_point, 1);
        }
        else if (a_point->second < b_point->first) {
            p.push_back({ a_point->first, n - 1 });
            p.push_back({ a_point->second, n });
            std::advance(a_point, 1);
        }
        else if (a_point->second > b_point->first) {
            std::advance(b_point, 1);
        }
    }

    p.sort();
    std::list<std::pair<std::string, int>>::iterator p_point = p.begin();
    std::list<std::pair<std::string, int>> f;
    std::list<std::pair<std::string, int>>::iterator f_point = f.begin();

    int d = 2;
    while (d < n) {

        // step 1
        bricks.a = c;
        bricks.b = c;


        // step 2
        c.clear();

        // step 3
        bricks.b.sort();
        bricks.a.sort(sortbysec);

        // step 4
        a_point = bricks.a.begin();
        b_point = bricks.b.begin();
        p_point = p.begin();

        std::list<std::pair<std::string, std::string>>::iterator end_a = bricks.a.end();
        std::advance(end_a, -1);

        std::list<std::pair<std::string, std::string>>::iterator end_b = bricks.b.end();
        std::advance(end_b, -1);

        std::list<std::pair<std::string, int>>::iterator end_p = p.end();
        std::advance(end_p, -1);

        // This is slightly different than instructed. The last two conditions were switched around and the final condition was reused within the second to last condition.
        while (a_point != bricks.a.end()) {
            if (a_point->second == b_point->first) {
                // std::cout << "1" << std::endl;
                c.push_back({ a_point->first, b_point->second });
                std::advance(a_point, 1);
                if (b_point != end_b) std::advance(b_point, 1);
            }
            else if (a_point->second == (p_point->first)) {
                // std::cout << "2" << std::endl;
                f.push_back({ a_point->first, p_point->second - d });
                std::advance(a_point, 1);
                if (p_point != end_p) std::advance(p_point, 1);
            }
            else if (a_point->second > b_point->first) {
                // std::cout << "4" << std::endl;
                if (b_point != end_b) std::advance(b_point, 1);
                else if (a_point->second > p_point->first) {
                    // std::cout << "3" << std::endl;
                    if (p_point != end_p) std::advance(p_point, 1);
                }
            }
            else if (a_point->second > p_point->first) {
                // std::cout << "3" << std::endl;
                if (p_point != end_p) std::advance(p_point, 1);
            }

        }


        // step 5
        f.sort();

        // step 6
        p.merge(f);
        p.sort();

        // step 7
        f.clear();

        // step 8
        d *= 2;
    }

    p.sort(sortbysecInt);
    std::list<std::string> results;

    p_point = p.begin();
    while (p_point != p.end()) {
        results.push_back(p_point->first);
        std::advance(p_point, 1);
    }
    std::ofstream myfile("test.txt");
    if (myfile.is_open()) {
        for (auto x : results) {
            myfile << x << "\n";
        }
        myfile.close();
    }

    return results;
}

// Main for running algorithm
int main(std::string argc, char* argv[]) {
    std::list<std::string> results = get_results(argv[1]);
    const std::string results_file = "results.txt";
    std::cout << "Writing results to " << results_file << std::endl;

    for (std::string x : results) std::cout << x << std::endl;
    std::ofstream myfile(results_file);
    if (myfile.is_open()) {
        for (auto x : results) {
            myfile << x << "\n";
        }
        myfile.close();
    }
}