//
// Created by kvitadmin on 10.11.2021.
//

#ifndef HOMEWORK27_4_1_TREE_H
#define HOMEWORK27_4_1_TREE_H


#include "bigbranch.h"

class Tree{
    int countBigBranch;
    BigBranch** pBigBranch = nullptr;
public:
    Tree(){
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        countBigBranch = (std::rand() % 3) + 3;
        pBigBranch = new BigBranch*[countBigBranch];
        for(int i = 0; i < countBigBranch; ++i){
            pBigBranch[i] = new BigBranch(this, "none");
        }
    }
    BigBranch* GetBigBranchPtr(int index){
        if(index >= 0 && index < countBigBranch) {
            return pBigBranch[index];
        }
        return nullptr;
    }
    int GetBigBranchCount() {
        return countBigBranch;
    }
};


#endif //HOMEWORK27_4_1_TREE_H
