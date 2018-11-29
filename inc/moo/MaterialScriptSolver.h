#ifndef __MATERIALSCRIPTSOLVER_H__
#define __MATERIALSCRIPTSOLVER_H__

#include "ResourceSolver.h"

namespace MM {

    ResourceSolverPtr findUnsolvedMaterialTextures(const String& group = Ogre::StringUtil::BLANK);

}

#endif // 
