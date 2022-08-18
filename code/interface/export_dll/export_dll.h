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
#define DELETE_PTR_EUQAL_NULLPTR(x) if((x) == nullptr)\
									{\
										return -1;\
									}

#define END_OF(x) /##/end of (x);

#define FOR_BEGIN for(;;){
#define FOR_END }
#endif