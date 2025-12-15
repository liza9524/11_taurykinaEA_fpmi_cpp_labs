#include "forward_list_impl.h"

ForwardList::ForwardList() : begin_(nullptr), size_(0) {}

ForwardList::ForwardList(const ForwardList& rhs) : begin_(nullptr), size_(0) 
    {
    Node* p = rhs.begin_;
    while (p != nullptr) 
    {
        PushBack(p->value_);
        p = p->next_;
    }
}
ForwardList::ForwardList(size_t count, int32_t value) : begin_(nullptr), size_(0) 
    {
    for (size_t i = 0; i < count; i++) 
    {
        PushBack(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init):begin_(nullptr), size_(0) 
{    
    for (int32_t x : init) 
    {
        PushBack(x);
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) 
{
  

if (this != &rhs) {
        ForwardList temp(rhs); 
        std::swap(begin_, temp.begin_);
        std::swap(size_, temp.size_);
    }
    return *this;
}

ForwardList::~ForwardList() 
{
    Clear();
}

void ForwardList::PushBack(int32_t value) 
{
    Node* chupep = new Node(value);
    if (begin_ == nullptr) 
    {
        begin_ = chupep;
    } else {
        Node* bob = begin_;
        while (bob->next_ != nullptr)
        {
            bob = bob->next_;
        }
        bob->next_ = chupep;
    }
    ++size_;
}

void ForwardList::PushFront(int32_t value) 
{
    Node* p = new Node(value);
    p->next_ = begin_;
    begin_ = p;
    size_++;
   
} 

void ForwardList::PopFront() 
{
    if (begin_ == nullptr)
    {
        throw "Error! List is empty!";
    }
    Node* temp = begin_;     
    begin_ = begin_->next_;  
    delete temp;  
    size_--;
}

void ForwardList::Remove(int32_t value)
{
   
    while ((begin_ != nullptr) && (begin_->value_ == value))
    {
        Node* temp = begin_;
        begin_ = begin_->next_;
        delete temp;
        --size_;
    }

    // Удаляем из середины/конца
    if (begin_ != nullptr)
    {
        Node* p = begin_;
        while (p->next_ != nullptr) 
        {
            if (p->next_->value_ == value) 
            {
                Node* temp = p->next_;
                p->next_ = p->next_->next_;
                delete temp;
                --size_;
            } 
            else
            {
                p = p->next_;
            }
        }
    }
}

void ForwardList::Clear() 
{
    while (begin_ != nullptr) 
    {
        PopFront();
    }
}

bool ForwardList::FindByValue(int32_t value) 
{
    Node* p = begin_;
    while (p != nullptr) 
    {
      
        if (p->value_ == value) 
        {
            return true;
        }
        p = p->next_;
    }
    return false;
}




void ForwardList::Print(std::ostream& out) 
{ 
    
        Node* p = begin_;
    while (p != nullptr) 
    {
        if (p == begin_) 
        {
            out << p->value_;
        } else
        {
            out << ' ' << p->value_;
        }
            p = p->next_;
    }    
}

 int32_t ForwardList::Front() const 
 {
    if (begin_ == nullptr) 
    {
        throw "Error! List is empty!";
    }
    return begin_->value_;
}

 size_t ForwardList::Size() const 
 {
     return size_;
 }