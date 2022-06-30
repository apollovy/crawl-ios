//
//  main.mm
//  dcss
//
//  Created by Аполлов Юрий Андреевич on 25.06.2022.
//
#import <Foundation/Foundation.h>


extern int DCSS_main(int argc, char* argv[]);

// https://stackoverflow.com/a/15318065/674557
char** cArrayFromNSArray(NSArray* array)
{
    int i, count = array.count;
    char** cargs = (char**) malloc(sizeof(char*) * (count + 1));
    for(i = 0; i < count; i++) {
        NSString *s = array[i];
        const char *cstr = s.UTF8String;
        int len = strlen(cstr);
        char* cstr_copy = (char*) malloc(sizeof(char) * (len + 1));
        strcpy(cstr_copy, cstr);
        cargs[i] = cstr_copy;
    }
    cargs[i] = NULL;
    return cargs;
}

extern "C" {
int CDDA_iOS_main(NSString* documentPath)
{
    NSArray<NSString*>* arguments = NSProcessInfo.processInfo.arguments;
    NSArray<NSString*>* newArguments = [arguments arrayByAddingObjectsFromArray:@[
        @"-dir", documentPath,

    ]];
    int newArgumentsCount = newArguments.count;
    char** stringArgs = cArrayFromNSArray(newArguments);

    return DCSS_main(newArgumentsCount, stringArgs);
}
}
