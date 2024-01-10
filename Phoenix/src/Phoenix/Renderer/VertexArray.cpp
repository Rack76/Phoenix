#include "pnpch.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "Phoenix/Platform/OpenGL/OpenGLVertexArray.h"

namespace Phoenix {
	VertexArray* VertexArray::Create() {
		switch (Renderer::GetAPI()) {
			case RendererAPI::None: PN_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
			case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}

		PN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}