/**
 * @file    OutputFile.h
 * @ingroup LoggerCpp
 * @brief   Output to the a file using fprintf
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

#include "Output.h"
#include "Config.h"


namespace Log
{


/**
 * @brief   Output to the standard console using fprintf
 * @ingroup LoggerCpp
 */
class OutputFile : public Output
{
public:
    /**
     * @brief Constructor : open the output file
     *
     * @param[in] aConfigPtr    Config the output file with "filename"
     */
    OutputFile(const Config::Ptr& aConfigPtr);

    /// @brief Destructor : close the file
    virtual ~OutputFile();

    /**
     * @brief Output the Log to the standard console using fprintf
     *
     * @param[in] aChannelPtr   The underlying Channel of the Log
     * @param[in] aLog          The Log to output
     */
    virtual void output(const Channel::Ptr& aChannelPtr, const Log& aLog) const;

private:
    void open() const;
    void close() const;
    void test_rotate(const long aSize) const;

private:
    mutable FILE* mpFile;   //!< File pointer (mutable to be modified in the const output method)

    /** 
     * @brief "max_startup_size" Size of the file above wich to create a new file instead of appending to it (at startup).
     *
     * Default (0) creates a new file at each startup (never append to an existing one).
    */
    long mMaxStartupSize;

    /** 
     * @brief "max_size" Size of the file above wich to create a new file instead of appending to it (at runtime).
     *
     * Default (1024*1024=1Mo) creates a new file each time the current one grow above 1Mo.
    */
    long mMaxSize;
    
    std::string mFilename;      //!< @brief "filename"      Name of the log file 
    std::string mFilenameOld;   //!< @brief "filename_old"  Name of the old log file
};


} // namespace Log
