#pragma once

#include <memory>
#include <string>

#include "AGraph.h"
#include "GVContext.h"
#include "GVRenderData.h"

#ifdef GVDLL
#if gvc___EXPORTS // CMake's substitution of gvc++_EXPORTS
#define GVLAYOUT_API __declspec(dllexport)
#else
#define GVLAYOUT_API __declspec(dllimport)
#endif
#endif

#ifndef GVLAYOUT_API
#define GVLAYOUT_API /* nothing */
#endif

namespace GVC {

/**
 * @brief The GVLayout class represents a graph layout
 */

class GVLayout {
public:
  GVLAYOUT_API GVLayout(const std::shared_ptr<GVContext> &gvc,
                        const std::shared_ptr<CGraph::AGraph> &g,
                        const std::string &engine);
  GVLAYOUT_API GVLayout(GVContext &&gvc, CGraph::AGraph &&g,
                        const std::string &engine);
  GVLAYOUT_API GVLayout(std::shared_ptr<GVContext> gvc, CGraph::AGraph &&g,
                        const std::string &engine);
  GVLAYOUT_API GVLayout(GVContext &&gvc, std::shared_ptr<CGraph::AGraph> g,
                        const std::string &engine);
  GVLAYOUT_API ~GVLayout();

  // default copy since we manage resources through movable types
  GVLAYOUT_API GVLayout(const GVLayout &) = default;
  GVLAYOUT_API GVLayout &operator=(const GVLayout &) = default;

  // default move since we manage resources through movable types
  GVLAYOUT_API GVLayout(GVLayout &&) = default;
  GVLAYOUT_API GVLayout &operator=(GVLayout &&) = default;

  // render the layout in the specified format
  GVLAYOUT_API GVRenderData render(const std::string &format) const;

private:
  std::shared_ptr<GVContext> m_gvc;
  std::shared_ptr<CGraph::AGraph> m_g;
};

} //  namespace GVC

#undef GVLAYOUT_API
