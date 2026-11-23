template <typename number = float,typename integer =unsigned short>
number custom_sqrt(number __l,integer max_attemps = 10,number __eq=0.01)
{
    //__l E [min_value,max_value]
    number max_value = (__l>=1)? __l: 1,
    min_value  = 0,med_value =0;
    //set custom_sqrt(0) = 0
    if(__l ==0 ) return 0 ;
    //
    const number result_square = __l*__l;
    //set max_attempts
    for (size_t i = 0; i != max_attemps  ; i++)
    {
        //set medium_value : m  m = max+ min /2
        med_value = (min_value + max_value)/ 2;
        //set min_value
        if (med_value*med_value >__l) max_value = med_value;
        else min_value = med_value;
        //set break fun
       if((med_value*med_value)-(result_square) <(__eq) && -(__eq)<(med_value*med_value) - (result_square)) break;
    }
    return med_value;
}
