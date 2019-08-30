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

#ifndef BLOCKOPERATION_H
#define BLOCKOPERATION_H

#include <osg/Referenced>
#include <osg/OperationThread>


class BlockOperation : public osg::Operation, public OpenThreads::Block
{

public:
	BlockOperation::BlockOperation():
	  osg::Operation("Block", false)
	  {
	  }

	  virtual void BlockOperation::release()
	  {
		  Block::release();
	  }

	  virtual void BlockOperation::operator () (osg::Object* object)
	  {
		  Block::release();
	  }
};



#endif
