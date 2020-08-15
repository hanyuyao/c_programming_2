#include "function.h"
#include <algorithm>

using namespace oj;

//note where begin_ , last_ , end_ point to

void Vector::pop_back()
{
    if(begin_ == nullptr) return;
    last_ = last_-1;
}

void Vector::push_back(value_type val)
{
    if(begin_ == nullptr){
        begin_ = new value_type[2];
        begin_[0] = val;
        last_ = end_ = begin_+1;
    }
    else{
        if(capacity() == size()){
            reserve(std::max(capacity()+1, capacity()*3));
        }
        last_[0] = val;
        last_ = last_+1;
    }
}

void Vector::reserve(size_type new_capacity)
{
    if(new_capacity <= capacity()) return;

    size_type s = size();
    end_ = new value_type[new_capacity+1];
    for(size_type i = 0; i < s; i++){
        end_[i] = begin_[i];
    }
    delete [] begin_;
    begin_ = end_;
    last_ = begin_ + s;
    end_ = begin_ + new_capacity;
}

Vector::~Vector()
{
    delete [] begin_;
    begin_ = last_ = end_ = nullptr;
}
