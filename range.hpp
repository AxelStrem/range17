#pragma once

#include <iterator>
#include <algorithm>

template<class V> struct default_step
{
    void operator()(V& value) const { value++; }
};

template<int v> struct int_step
{
    template<class V> 
    void operator()(V& value) const { value+=v; }
};

template<class V> struct step
{
    V s;
    
    void operator()(V& value) const { value+=s; }
    step(V step_) : s(step_) {}
};

template<class V, typename Step = default_step<V>, typename Compare = std::less<V>> class range
{
    V left;
    V right;

    Compare comp;
    Step next;
public:
    struct Sentinel
    {
        V value;
    };
    class Iterator : public std::iterator<std::forward_iterator_tag, V, V>
    {
        V value;
        Compare comp;
        Step next;
    public:
        Iterator(V val, Compare c, Step n) : value(val), comp(c), next(n) {}
        Iterator(const Iterator& i) : value(i.value), comp(i.comp), next(i.next) {}

        V operator*() { return value; }
        Iterator operator++() { next(value); return *this; }
        Iterator operator++(int) { Iterator i = *this; next(value); return i; }
        bool operator!=(const Sentinel& i) const
        {
            return comp(value, i.value);
        }
        bool operator==(const Sentinel& i) const
        {
            return !((*this) != i);
        }
    };

    range(const range& r) : left(r.left, r.right) {}
    range(V l, V r, Step s = {}, Compare c = {}) : left(l), right(r), next(s), comp(c) {}

    Iterator begin() const
    {
        return Iterator(left, comp, next);
    }

    Sentinel end() const
    {
        return Sentinel{ right };
    }
};
