#include <util/util_Convert.hpp>

namespace util
{
    std::string Format128NintendoStyle(AccountUid value)
    {
        u8 *bytesval = (u8*)value.uid;
        std::stringstream strm;

        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[3];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[2];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[1];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[0];
        strm << "-";
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[5];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[4];
        strm << "-";
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[7];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[6];
        strm << "-";
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[9];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[8];
        strm << "-";
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[15];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[14];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[13];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[12];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[11];
        strm << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << (int)bytesval[10];

        return strm.str();
    }

    u64 Get64FromString(std::string val)
    {
        return strtoull(val.c_str(), NULL, 16);
    }

    std::string FormatApplicationId(u64 app_id)
    {
        std::stringstream strm;
        strm << std::uppercase << std::setfill('0') << std::setw(16) << std::hex << app_id;
        return strm.str();
    }

    std::string FormatResultDisplay(Result rc)
    {
        char res[0x20] = {0};
        sprintf(res, "%04d-%04d", R_MODULE(rc) + 2000, R_DESCRIPTION(rc));   
        return std::string(res);
    }

    std::string FormatResultHex(Result rc)
    {
        char res[0x20] = {0};
        sprintf(res, "0x%X", rc);
        return std::string(res);
    }

    std::string FormatResult(Result rc)
    {
        auto desc = RES_DESCRIPTION(rc);
        if(desc.empty()) return desc;
        return "(" + FormatResultDisplay(rc) + ") " + desc;
    }
}