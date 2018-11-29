#ifndef __SCENESOLVER_H__
#define __SCENESOLVER_H__

#include "ResourceSolver.h"

namespace MM {
    class SceneInfo;

    ResourceSolverPtr findUnsolvedSceneItems(SceneInfo* sceneInfo);

}

#endif // 
