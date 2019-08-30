/* -*-c++-*- VirtualPlanetBuilder - Copyright (C) 1998-2007 Robert Osfield
 *
 * This library is open source and may be redistributed and/or modified under
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * OpenSceneGraph Public License for more details.
*/

#ifndef THREADPOOL_H
#define THREADPOOL_H 1



#include "BlockOperation.h"


class ThreadPool : public osg::Object
{
     public:
     
        ThreadPool(unsigned int numThreads=0);
        
        ThreadPool(const ThreadPool&, const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY);

        META_Object(vpb, ThreadPool)

        void startThreads();
        
        void stopThreads();
        
        void run(osg::Operation* op);

        void waitForCompletion();
        
        unsigned int getNumOperationsRunning() const;
        
        bool done() const { return _done; }
        
    protected:
    
        virtual ~ThreadPool();
    
        void init();
   

        osg::ref_ptr<osg::OperationQueue>   _operationQueue;

        typedef std::list< osg::ref_ptr<osg::OperationThread> > Threads;
        
        unsigned int                        _numThreads;
        
        Threads                             _threads;
     
        mutable OpenThreads::Mutex          _mutex;
        unsigned int                        _numRunningOperations;
        bool                                _done;
        osg::ref_ptr<BlockOperation>        _blockOp;
        
        unsigned int                         _maxNumberOfOperationsInQueue;
       
};

#endif

