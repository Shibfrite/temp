int write_with_overflow_prevention(char *buffer, int buffer_size, const char *content, int content_len, t_format *fmt)
{   
    int total_written;
    int content_written;
    int i;
    int initial_width;
    
    initial_width = fmt->width;
    total_written = 0;
    content_written = 0;
    while (content_written < content_len || total_written < content_len + initial_width)
    {
        i = 0;
        if (!fmt->minus)
            add_padding(buffer, &i, &fmt->width);
        while (i < buffer_size - 1 && content_written < content_len)
            buffer[i++] = content[content_written++];
        if (fmt->minus)
            add_padding(buffer, &i, &fmt->width);
        total_written += write(1, buffer, i);
    }
    return total_written;
}
