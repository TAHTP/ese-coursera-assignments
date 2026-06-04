#include<stdio.h> 
#include<stdint.h> 
#include"data.h" 
#include "memory.h"




uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
   uint8_t *start ;
   start = ptr ;
   int32_t tmp = data; 
   uint32_t u_data ; 
   if(data<0){
    u_data=(uint32_t)(-data ); 
     ptr++;
     *start='-' ; 
   }
   else u_data = data ;  
  do{
   if(u_data%base >=10 ) *(ptr++) = u_data%base+55 ;
   else *(ptr++) =u_data%base+48 ; 
    u_data/=base ;
   } while(u_data !=0 ) ;
   if(tmp<0)my_reverse(start+1,ptr-start-1);
   else my_reverse(start,ptr-start);
   *(ptr++)='\0' ; 
  return ptr -start ; 
}
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    uint8_t flag = 0 ;
    digits--; 
  if(*(ptr) == '-'){
        flag = 1  ; 
        ++ptr ; 
        --digits ; 
  }
  uint32_t res = 0 ; 
  uint32_t tmp = 0 ; 
  while(digits--){
      if(*(ptr) <= 'f'  && *(ptr) >='a'   )  tmp  = (*(ptr) - 87) ;
      else if(*(ptr) <= 'F'  && *(ptr) >='A'   )  tmp  = (*(ptr) - 87-32) ;
      else  tmp =  (*(ptr) - 48) ; 
      res = res *base + tmp ; 
      ptr++ ; 
  }
  if(flag==1) res = -res ; 
  return res ; 

}