#include <iostream>
#include <cassert>
#include <utility>

class MiddleBranch{
    class BigBranch* bigBranch = nullptr;
    std::string elfName;
public:
    MiddleBranch(class BigBranch* inBigBranch, std::string name) : bigBranch(inBigBranch), elfName(std::move(name)){
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
    BigBranch(class Tree* inTree, std::string name): tree(inTree), elfName(std::move(name)){
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
    void SetElfName(std::string& name){
        this->elfName = std::move(name);
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
        if(index >= 0 && index < countBigBranch) {
            return pBigBranch[index];
        }
        return nullptr;
    }
    int GetBigBranchCount() {
        return countBigBranch;
    }
};

int main() {
    Tree myTree;
    for(int i = 0; i < myTree.GetBigBranchCount(); ++i){
        std::string elfName = "Elf" + std::to_string(i+1);
        myTree.GetBigBranchAt(i)->SetElfName(elfName);
        std::cout << "Big branch #" << i << " Elf name is " << myTree.GetBigBranchAt(i)->GetElfName() << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
