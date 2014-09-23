//
//  SF_FileSystem.h
//  SwipeFootball
//
//  Created by Sid on 07/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __SwipeFootball__SF_FileSystem__
#define __SwipeFootball__SF_FileSystem__
#include <string>

/** File located inside a app bundle */
class File {
public:
    
    /** Create a File object.
     * @param file Example: "HelloWorld"
     * @param extension Example ".png"
     */
    File(const std::string &file, const std::string &extension);
    
    /** @return Absolute path */
    std::string GetAbsolutePath() const;
    
    /** Read the contents of file 
     * @return Contents of the file.
     */
    std::string GetContents() const;

private:
    std::string file_;
    std::string extension_;
};

#endif /* defined(__SwipeFootball__SF_FileSystem__) */
