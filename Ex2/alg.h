#include<algorithm>

template<class InputIt, class Number>
InputIt Add_n(InputIt first, InputIt last, const Number n)
{
    InputIt it = first;
    auto del=*it;
    while(it!=last)
    {   
        del=*it;     
        for(Number i=1; i!=n; ++i)
        {  
            ++it;
            if(it==last)
            break; 
            del+=*it;
        }
        *first=del;
        first++;
        if(it!=last)
         ++it;
    }
    return first;
}
