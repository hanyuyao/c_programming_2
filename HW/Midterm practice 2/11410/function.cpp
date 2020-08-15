#include<iostream>
#include"function.h"

using namespace oj;
using namespace std;

Vector::Vector()
{
    begin_ = end_ = last_ = nullptr;
}

size_t Vector::capacity() const
{
    if(begin_ == nullptr) return 0;
    return end_ - begin_ + 1;
}

size_t Vector::size() const
{
    if(last_ == nullptr) return 0;
    return last_ - begin_ + 1;
}

void Vector::pop_back()
{
    if(size() > 1)
        last_ = last_-1;
    else
        last_ = nullptr;
}

void Vector::push_back(value_type val)
{
    if(capacity() > size()){
        last_ = last_+1;
        *last_ = val;
    }
    else{
        reserve(max(capacity()+1, capacity()*3));
        last_ = begin_+size();
        *last_ = val;
    }
}

void Vector::insert(size_type pos,size_type count,value_type val)
{
    if(begin_ == nullptr){
        begin_ = new data_t[count];
        for(int i = 0; i < count; i++)
            begin_[i] = val;
        last_ = begin_+count-1;
        end_ = last_;
    }
    else if(last_ == nullptr){
        if(count > capacity())
            reserve(max(capacity()*3/2, capacity()+count));
        for(int i = 0; i < count; i++)
            begin_[i] = val;
        last_ = begin_ + count - 1;
    }
    else{
        if(size()+count > capacity())
            reserve(max(capacity()*3/2, capacity()+count));

        //index of last_ : size()-1
        for(size_t i = size()-1; i >= pos; i--){
            begin_[i+count] = begin_[i];
            //cout << i << endl;
        }
        for(size_t i = pos; i < pos+count; i++){
            begin_[i] = val;
        }
        last_ = last_+count;
    }
}

void Vector::reserve(size_type new_capacity)
{
    if(new_capacity <= capacity()) return;
    size_t s = size();  //original size
    end_ = new data_t[new_capacity];
    for(size_t i = 0; i < s; i++)
        end_[i] = begin_[i];
    delete [] begin_;
    begin_ = end_;
    end_ = begin_+new_capacity-1;
    if(s != 0)
        last_ = begin_+s-1;
    else
        last_ = nullptr;
}

void Vector::resize(size_type new_size)
{
    if(new_size > size()){
        if(new_size > capacity())
            reserve(new_size);
        for(int i = size(); i < new_size; i++)
            begin_[i] = 0;
        last_ = begin_ + new_size - 1;
    }
    else if(new_size == 0){
        last_ = nullptr;
    }
    else{
        last_ = begin_+new_size-1;
    }
}

Vector::~Vector()
{
    delete [] begin_;
    begin_ = last_ = end_ = nullptr;
}
