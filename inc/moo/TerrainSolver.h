#ifndef __TERRAINSOLVER_H__
#define __TERRAINSOLVER_H__

#include "ResourceSolver.h"

namespace MM {
    class Terrain;

    ResourceSolverPtr findUnsolvedTerrainBrushes(Terrain* terrain);

}

#endif // 
