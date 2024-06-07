#pragma once

class VertexBuffer
{
    private:
        unsigned int m_rendererID;
        unsigned int m_size;

    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

        inline unsigned int getCount() const {return m_size/sizeof(float);}
};