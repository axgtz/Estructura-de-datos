//
//  main.cpp
//  Priority_Queue
//
//  Created by Alex Gutz on 5/11/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
struct cmp{
    
    bool operator()(std::pair&lt;double,int&gt; a, std::pair;&lt;double,int&gt; b)
    
    {
        
        return a.first &gt; b.first;
        
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
