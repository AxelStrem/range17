# C++17 numeric interval 
## (ranged-based for loop friendly)

- Basic range:

        for(auto x : range(0,10) )
        { /* ... */ }  //  0,1,2,3,4,5,6,7,8,9

- Custom step:  

       for(auto x : range(-10, 10, step{2}) )
       { /* ... */ }  //  -10,-8,-6,-4,-2,0,2,4,6,8

- Custom constexpr step:  

       for(auto x : range(0, 20, int_step<3>{}) )
       { /* ... */ }  //  0,3,6,9,12,15,18

- Custom lambda step:  

       for(auto x : range(1, 20, [](auto& v){ v = 2*v; }) )
       { /* ... */ }  //  1,2,4,8,16
       
- Other types:  

       for(auto x : range(0.5f, 5.3f, step{0.7f}) )
       { /* ... */ }  // 0.5,1.2,1.9,2.6,3.3,4.0,4.7

- Custom comparison - inclusive right border:  

       for(auto x : range(5, 10, step{1}, std::less_equal{}) )
       { /* ... */ }  //  5,6,7,8,9,10

- Custom comparison - reversed traversal:  

       for(auto x : range(10, 0, step{-1}, std::greater{}) )
       { /* ... */ }  //  10,9,8,7,6,5,4,3,2,1

The last example can be somewhat improved syntactically (default to `std::greater` depending on `step`).
