#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>

int partA(std::ifstream *file) {
    using std::vector, std::ifstream;

    vector<int> lhs, rhs;
    int lhi, rhi, sum = 0;
    int lhc, rhc;

    for(int i = 0, num; *file >> lhi, *file >> rhi; i++) {
        lhs.push_back(lhi);
        rhs.push_back(rhi);
    }

    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    lhs.push_back(0);
    rhs.push_back(0);


    for(int i = 0; i < lhs.size(); i++) {
        lhc = 0;
        rhc = 0;

        sum+= abs((lhs.at(i) - rhs.at(i)));
    }

    return sum;
}

int partB(std::ifstream *file) {
    std::map<int, int> lhs, rhs; //left / right hand side
    int sum = 0;

    for(int lhi, rhi; *file >> lhi, *file >> rhi; ) {
        lhs[lhi]++;
        rhs[rhi]++;
    }

    for(auto const& x : lhs) {
        if(rhs.contains(x.first)) {
            //value times count on the left times count on the right
            sum+=x.second * x.first * rhs[x.first];
        }
    }

    return sum;
}

int main(void) {
    using std::ifstream;
    ifstream file("day01input.txt");

    if(!file.is_open()) {
        return 1;
    }
    
    std::cout << partB(&file) << '\n';
}