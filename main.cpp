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
        assert(inTree != nullptr);
        countMiddleBranch = (std::rand() % 2) + 2;
        pMiddleBranch = new MiddleBranch*[countMiddleBranch];
        for(int i = 0; i < countMiddleBranch; ++i){
            pMiddleBranch[i] = new MiddleBranch(this, "None");
        }
    }
    std::string GetElfName(){
        return this->elfName;
    }
    void SetElfName(std::string name){
        this->elfName = name;
    }
};

class Tree{
    int countBigBranch;
    BigBranch** pBigBranch = nullptr;
public:
    Tree(){
        countBigBranch = (std::rand() % 3) + 3;
        pBigBranch = new BigBranch*[countBigBranch];
        for(int i = 0; i < countBigBranch; ++i){
            pBigBranch[i] = new BigBranch(this, "None");
        }
    }
    BigBranch* GetBigBranchAt(int index){
        return this->pBigBranch[index];
    }
    int GetBigBranchCount(){
        return this->countBigBranch;
    }
};

int main() {
    Tree myTree;
    for(int i = 0; i < myTree.GetBigBranchCount(); ++i){
        myTree.GetBigBranchAt(i)->SetElfName(std::string("Elf" + std::to_string(i+1)));
        std::cout << "Big branch #" << i << " Elf name is " << myTree.GetBigBranchAt(i)->GetElfName() << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
