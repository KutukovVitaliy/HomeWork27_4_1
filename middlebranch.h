//
// Created by kvitadmin on 10.11.2021.
//

#ifndef HOMEWORK27_4_1_MIDDLEBRANCH_H
#define HOMEWORK27_4_1_MIDDLEBRANCH_H


#include <cassert>
#include <utility>
#include <ctime>

class MiddleBranch{
    class BigBranch* bigBranch = nullptr;
    std::string elfName;
public:
    MiddleBranch(class BigBranch* inBigBranch, std::string inName) : bigBranch(inBigBranch), elfName(std::move(inName)){
        assert(inBigBranch != nullptr);
    }
    std::string GetElfName(){
        return this->elfName;
    }
    void SetElfName(std::string& name){
        this->elfName = std::move(name);
    }
};

#endif //HOMEWORK27_4_1_MIDDLEBRANCH_H
