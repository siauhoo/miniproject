//
// Created by charles.cxh on 2021/9/4.
//

#ifndef MINIPROJECT_SYSINFO_H
#define MINIPROJECT_SYSINFO_H

#define INVERT32(x) ((((x)>>24)&0x000000FF)|(((x)>>8)&0x0000FF00)|(((x)<<8)&0x00FF0000)|(((x)<<24)&0xFF000000))
#define INVERT64(x) ((((x)>>56)&0x00000000000000FF)|(((x)>>40)&0x000000000000FF00)|(((x)>>24)&0x0000000000FF0000)|(((x)>>8 )&0x00000000FF000000) |(((x)<<8 )&0x000000FF00000000) |(((x)<<24)&0x0000FF0000000000) |(((x)<<40)&0x00FF000000000000) |(((x)<<56)&0xFF00000000000000) ) \

namespace sysinfo {

    typedef unsigned char uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned int uint32_t;
    typedef unsigned long long uint64_t;

    typedef signed char int8_t;
    typedef signed int int32_t;
    typedef signed long long int64_t;

    typedef float FLOAT32;
    typedef double FLOAT64;

    typedef union {
        int8_t i_data[4];
        uint8_t u_data[4];
        char data[4];
        int32_t i;
        uint32_t u;
        FLOAT32 f;
    } TData32;

    typedef union {
        int8_t i_data[8];
        uint8_t u_data[8];
        char data[8];
        int64_t i;
        uint64_t u;
        FLOAT64 f;
    } TData64;


    /**
    * 测试该系统是否是 big endian 编码
    * @return 如果是返回true，否则false
    */
    inline bool IsBigEndian() {
        const sysinfo::uint16_t u16 = 0x00AA;
        const sysinfo::uint8_t *pu8 = (const sysinfo::uint8_t *) &u16;
        return (pu8[0] == 0);
    }

    /**
    * 测试该系统是否是 little endian 编码
    * @return 如果是返回true，否则false
    */
    inline bool IsLittleEndian() {
        return (!IsBigEndian());
    }

    /**
    * uint32_t大端小端转换
    * @param[in] val 要转换的值
    * @return 返回转换后的值
    */
    inline uint32_t ntoh32(uint32_t val) {
        if (sysinfo::IsLittleEndian())
            return val;

        return INVERT32(val);
    }

    /**
    * uint64_t大端小端转换
    * @param[in] val 要转换的值
    * @return 返回转换后的值
    */
    inline uint64_t ntoh64(uint64_t val) {
        if (sysinfo::IsLittleEndian())
            return val;

        return INVERT64(val);
    }


    /**
    * int32_t大端小端转换
    * @param[in] val 要转换的值
    * @return 返回转换后的值
    */
    inline int32_t ntoh32(int32_t val) {
        return ((uint32_t) ntoh32((uint32_t) val));
    }

    /**
    * int64_t大端小端转换
    * @param[in] val 要转换的值
    * @return 返回转换后的值
    */
    inline int64_t ntoh64(int64_t val) {
        return ((uint64_t) ntoh64((uint64_t) val));
    }

    /**
     * int8_t大端小端转换
     * @param z
     * @return
     */

    inline int8_t ReadInt8(char z) {
        int8_t ret = (int8_t) (z);
        return ret;
    }

    /**
     * int32_t读取
     * @param z
     * @return
     */
    inline int32_t ReadInt32(char z[4]) {
        TData32 tmp;
        tmp.i_data[0] = ReadInt8(z[0]);
        tmp.i_data[1] = ReadInt8(z[1]);
        tmp.i_data[2] = ReadInt8(z[2]);
        tmp.i_data[3] = ReadInt8(z[3]);

        return ntoh32(tmp.i);
    }

    /**
     * uint8_t读取
     * @param z
     * @return
     */
    inline uint8_t ReadUInt8(char z) {
        uint8_t ret = (uint8_t) ReadInt8(z);
        return ret;
    }


    /**
     * uint32_t读取
     * @param z
     * @return
     */
    inline uint32_t ReadUInt32(char z[4]) {
        uint32_t ret = (uint32_t) ReadInt32(z);
        return ret;
    }


    /**
     * FLOAT64读取
     * @param z
     * @return
     */
    inline FLOAT64 ReadFloat64(char z[8]) {
        TData64 tmp;
        tmp.i_data[0] = ReadInt8(z[0]);
        tmp.i_data[1] = ReadInt8(z[1]);
        tmp.i_data[2] = ReadInt8(z[2]);
        tmp.i_data[3] = ReadInt8(z[3]);

        tmp.i_data[4] = ReadInt8(z[4]);
        tmp.i_data[5] = ReadInt8(z[5]);
        tmp.i_data[6] = ReadInt8(z[6]);
        tmp.i_data[7] = ReadInt8(z[7]);

        tmp.i = ntoh64(tmp.i);

        return tmp.f;
    }

}
#endif //MINIPROJECT_SYSINFO_H
