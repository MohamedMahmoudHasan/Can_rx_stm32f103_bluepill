
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define NULL 0                   


#define    SET_BIT(REG,BIT)    (REG |= (1 << BIT))

#define    CLR_BIT(REG,BIT)    (REG &= ~(1 << BIT))

#define    TOG_BIT(REG,BIT)    (REG ^= ( 1 << BIT))

#define    GET_BIT(REG,BIT)    ((REG>>BIT) & 1)

#define    IS_CLR(REG,BIT)  (!(REG & (1<<BIT)))

#define    IS_SET(REG,BIT)     (REG & (1<<BIT))



#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#define GET_BIT(REG,BIT)  ((REG >> BIT) & 1  )


#endif
