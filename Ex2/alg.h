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

template<class InputIt>
InputIt Transpose (InputIt start, InputIt end)
{ 

    InputIt it= start;
    
    for(;;)
    {
      it=start+1;
      if(it==end||start==end)
        break;
      auto temp = *it;
      *it=*start;
      *start=temp;
      start+=2;
    }
    return start;
}


template<class InputIt, class OutputIt, class BinaryOperation>
OutputIt Transform(InputIt start, InputIt end, OutputIt dest, BinaryOperation f)
{
    //if it's an empty container, or has an odd length
    if(start==end || std::distance(start,end)%2!=0)
    {
        return dest;
    }

    for(;start!=end;start+=2 )
    {
        InputIt it= start+1;
        *dest = f(*start,*it);
        dest++;
    }
    return dest;
}
