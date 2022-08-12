#ifndef EXPORT__DLL__H__ZYS
#define EXPORT__DLL__H__ZYS
#define EXPORT_DLL __declspec(dllexport)
#define IMPORT_DLL __declspec(dllimport)
#define YYDS_BEGIN namespace yyds{
#define YYDS_END };
#define YYDS yyds
#define DELETE_PTR(x) (delete (x));\
						((x) = nullptr);

#define DELETE_PTR_FUNCTION_ERROR(x,p) if(x != 0) \
								{\
									delete p;\
									p = nullptr;\
								}

#endif