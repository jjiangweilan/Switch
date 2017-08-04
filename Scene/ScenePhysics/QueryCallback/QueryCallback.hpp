//
//  QueryCallback.hpp
//  switch
//
//  Created by jiehong jiang on 8/4/17.
//
//

#ifndef QueryCallback_hpp
#define QueryCallback_hpp
#include "Box2D/Box2D.h"
class QueryCallback : public b2QueryCallback {
public:
    QueryCallback() : empty_(true){};
    ~QueryCallback() {};
    
    /// Called for each fixture found in the query AABB.
    /// @return false to terminate the query.
    virtual bool ReportFixture(b2Fixture* fixture) override;
    bool isEmpty();
private:
    bool empty_;
};

#endif /* QueryCallback_hpp */
