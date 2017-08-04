//
//  QueryCallback.cpp
//  switch
//
//  Created by jiehong jiang on 8/4/17.
//
//

#include "QueryCallback.hpp"
bool QueryCallback::ReportFixture(b2Fixture* fixture){
    empty_ = false;
    return false;
}

bool QueryCallback::isEmpty(){
    return empty_;
}
