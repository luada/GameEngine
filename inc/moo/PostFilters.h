#ifndef ___PostFilters_H__
#define ___PostFilters_H__

#include "PostFilterFactory.h"

namespace MM {

extern PostFilterFactory* getHeatVisionPostFilterFactory(void);
extern PostFilterFactory* getBloomPostFilterFactory(void);
extern PostFilterFactory* getFloodlightingPostFilterFactory(void);
extern PostFilterFactory* getFadePostFilterFactory(void);
extern PostFilterFactory* getMotionBlurPostFilterFactory(void);

extern void registerAllPostFilterFactories(PostFilterManager* postFilterManager);

}

#endif // 
