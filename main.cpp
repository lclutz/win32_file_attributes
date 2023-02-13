#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define CHECK(FA, ATTR) if (FA & ATTR) printf("\t" #ATTR "\n")

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Usage: file_attributes.exe <PATHS>\n");
    }

    for (int i = 1; i < argc; ++i)
    {
        printf("%s:\n", argv[i]);
        DWORD file_attributes = GetFileAttributesA(argv[i]);
        if (file_attributes == INVALID_FILE_ATTRIBUTES) {
            printf("\tINVALID_FILE_ATTRIBUTES\n");
            continue;
        }

        CHECK(file_attributes, FILE_ATTRIBUTE_READONLY);
        CHECK(file_attributes, FILE_ATTRIBUTE_HIDDEN);
        CHECK(file_attributes, FILE_ATTRIBUTE_SYSTEM);
        CHECK(file_attributes, FILE_ATTRIBUTE_DIRECTORY);
        CHECK(file_attributes, FILE_ATTRIBUTE_ARCHIVE);
        CHECK(file_attributes, FILE_ATTRIBUTE_DEVICE);
        CHECK(file_attributes, FILE_ATTRIBUTE_NORMAL);
        CHECK(file_attributes, FILE_ATTRIBUTE_TEMPORARY);
        CHECK(file_attributes, FILE_ATTRIBUTE_SPARSE_FILE);
        CHECK(file_attributes, FILE_ATTRIBUTE_REPARSE_POINT);
        CHECK(file_attributes, FILE_ATTRIBUTE_COMPRESSED);
        CHECK(file_attributes, FILE_ATTRIBUTE_OFFLINE);
        CHECK(file_attributes, FILE_ATTRIBUTE_NOT_CONTENT_INDEXED);
        CHECK(file_attributes, FILE_ATTRIBUTE_ENCRYPTED);
        CHECK(file_attributes, FILE_ATTRIBUTE_INTEGRITY_STREAM);
        CHECK(file_attributes, FILE_ATTRIBUTE_VIRTUAL);
        CHECK(file_attributes, FILE_ATTRIBUTE_NO_SCRUB_DATA);
        CHECK(file_attributes, FILE_ATTRIBUTE_EA);
        CHECK(file_attributes, FILE_ATTRIBUTE_PINNED);
        CHECK(file_attributes, FILE_ATTRIBUTE_UNPINNED);
        CHECK(file_attributes, FILE_ATTRIBUTE_RECALL_ON_OPEN);
        CHECK(file_attributes, FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS);
        CHECK(file_attributes, FILE_ATTRIBUTE_STRICTLY_SEQUENTIAL);
    }

    return 0;
}
