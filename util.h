#ifndef __UTIL_H__
#define __UTIL_H__

#include <cstdio>

using namespace std;

#include "rply.h"
#include "geom.h"
#include "cuPrintf.cuh"

static void HandleError( cudaError_t err,
                         const char *file,
                         int line ) {
    if (err != cudaSuccess) {
        printf( "HandleError:%s in %s at line %d\n", cudaGetErrorString( err ),
                file, line );
	cudaPrintfEnd();
	fflush(stdout);
        exit( EXIT_FAILURE );
    }
}

#define HANDLE_ERROR( err ) (HandleError( err, __FILE__, __LINE__ ))
#define CHECK_ERROR() HANDLE_ERROR( cudaGetLastError() )
static int vertex_cb(p_ply_argument argument);
static int face_cb(p_ply_argument argument);
Mesh * loadMeshFromPLY(const char * filename);
void printMesh(Mesh * m);

#endif
