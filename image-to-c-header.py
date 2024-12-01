import os
from PIL import Image

def bmp_to_rgb565_array(image_path):
    """
    将单个 BMP 图像转换为 RGB565 格式的像素数组
    """
    img = Image.open(image_path).convert("RGB")  # 确保是 RGB 格式
    width, height = img.size
    pixel_data = []

    for y in range(height):
        for x in range(width):
            r, g, b = img.getpixel((x, y))
            rgb565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
            pixel_data.append(rgb565)

    return width, height, pixel_data

def generate_c_array_from_folder(folder_path, output_file):
    """
    将指定文件夹内的所有图像转换为 RGB565 格式，并生成 C 头文件
    """
    # 获取文件夹中的所有图像文件
    image_files = sorted([f for f in os.listdir(folder_path) if f.lower().endswith(('.bmp', '.png', '.jpg', '.jpeg'))])

    if not image_files:
        print("未在文件夹中找到支持的图像文件。")
        return

    with open(output_file, "w") as f:
        f.write("// 自动生成的 RGB565 帧数据\n\n")
        f.write("#ifndef FRAMES_H\n#define FRAMES_H\n\n")
        f.write("#include <stdint.h>\n\n")

        frame_count = 0
        for image_file in image_files:
            image_path = os.path.join(folder_path, image_file)
            width, height, pixels = bmp_to_rgb565_array(image_path)

            if frame_count == 0:  # 记录第一帧的宽度和高度
                f.write(f"const uint16_t FRAME_WIDTH = {width};\n")
                f.write(f"const uint16_t FRAME_HEIGHT = {height};\n\n")

            # 写入每帧数据
            f.write(f"const uint16_t frame_{frame_count}[] PROGMEM = {{\n")
            for i, p in enumerate(pixels):
                f.write(f"0x{p:04X}, ")
                if (i + 1) % 16 == 0:  # 每行写 16 个像素值
                    f.write("\n")
            f.write("\n};\n\n")
            frame_count += 1

        # 写入帧数组指针
        f.write("const uint16_t* frames[] PROGMEM = {\n")
        for i in range(frame_count):
            f.write(f"    frame_{i},\n")
        f.write("};\n\n")
        f.write(f"const uint16_t FRAME_COUNT = {frame_count};\n\n")
        f.write("#endif // FRAMES_H\n")

    print(f"成功生成 C 头文件：{output_file}")

# 示例使用
if __name__ == "__main__":
    input_folder = input("请输入图像文件夹路径：").strip()
    output_header = "frames.h"
    generate_c_array_from_folder(input_folder, output_header)
