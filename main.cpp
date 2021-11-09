#include <iostream>
#include <cassert>

class MiddleBranch{
    class BigBranch* bigBranch = nullptr;
    std::string elfName;
public:
    MiddleBranch(class BigBranch* inBigBranch, std::string name) : bigBranch(inBigBranch), elfName(name){
        assert(inBigBranch != nullptr);
    }
    std::string GetElfName(){
        return this->elfName;
    }
};

class BigBranch{
    class Tree* tree;
    int countMiddleBranch;
    MiddleBranch** pMiddleBranch = nullptr;
    std::string elfName;
public:
    BigBranch(class Tree* inTree, std::string name): tree(inTree), elfName(name){
        countMiddleBranch = (std::rand() % 2) + 2;
        pMiddleBranch = new MiddleBranch*[countMiddleBranch];
        for(int i = 0; i < countMiddleBranch; ++i){
            pMiddleBranch[i] = new MiddleBranch(this, "None");
        }
    }
};

class Tree{
    int countBigBranch;
    BigBranch** pBigBranch = nullptr;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
