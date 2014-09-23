//
//  SF_FileSystem.cpp
//  SwipeFootball
//
//  Created by Sid on 07/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "FileSystem.h"
#include <cassert>
#include <fstream>
#include <sstream>
#include <CoreFoundation/CoreFoundation.h>

File::File(const std::string &file, const std::string &extension) :
file_(file),
extension_(extension)
{}

std::string File::GetAbsolutePath() const
{
    std::string ret;
    
    CFBundleRef bundle = CFBundleGetMainBundle();    
    CFStringRef resourceName = CFStringCreateWithCString(kCFAllocatorDefault, file_.c_str(), kCFStringEncodingUTF8);
    CFStringRef resourceType = CFStringCreateWithCString(kCFAllocatorDefault, extension_.c_str(), kCFStringEncodingUTF8);
    CFURLRef resourceURL = CFBundleCopyResourceURL(bundle, resourceName, resourceType, NULL);
    assert(resourceURL); // No resource in bundle
    CFStringRef resourcePath = CFURLCopyFileSystemPath(resourceURL, kCFURLPOSIXPathStyle);
    
    const char *resourcePathData = CFStringGetCStringPtr(resourcePath, kCFStringEncodingUTF8);
    if (resourcePathData) {
        ret = std::string(resourcePathData);
    } else {
        /* take the long route */
        CFIndex bufferSize = CFStringGetLength(resourcePath) + 1;
        char *buffer = new char[bufferSize];
        if (CFStringGetCString(resourcePath, buffer, bufferSize, kCFStringEncodingUTF8)) {
            ret = std::string(buffer);
        }
        delete [] buffer;
    }
    
    CFRelease(resourcePath);
    CFRelease(resourceURL);
    CFRelease(resourceType);
    CFRelease(resourceName);
    
    assert(ret.size());
    return ret;
}

std::string File::GetContents() const
{
    std::ifstream fin(GetAbsolutePath());
    std::stringstream ss;
    ss << fin.rdbuf();
    
    return ss.str();
}
