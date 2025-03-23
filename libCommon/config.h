#pragma once

#ifdef LIBCOMMON_EXPORTS
#define LIBCOMMON_EXPORTS_API __declspec(dllexport)
#else
#define LIBCOMMON_EXPORTS_API __declspec(dllimport)
#endif // LIBCOMMON_EXPORTS;
