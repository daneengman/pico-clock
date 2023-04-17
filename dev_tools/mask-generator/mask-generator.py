import os
import math

def main():
  files = os.listdir("masks")

  masks = []
  
  for path in files:
    with open(f"masks/{path}") as f:
      error = False
      vals = {}
      vals["name"] = path
      lines = f.readlines()
      print(lines)
      result = ""
      if len(lines) == 0:
        masks.append(f"{path}: error - text file is empty")
        continue
      width = len(lines[0].strip())
      for line in lines:
        line = line.strip()
        print(line)
        if(len(line) != width):
          masks.append(f"{path}: error - text file does not contain rectangular matrix")
          error = True
          break
        result = result + line
      if error: continue

      print(result)
      length = len(result)
      vals["int_type"] = 2**math.ceil(math.log2(length))
      vals["dims"] = (len(lines), width)
      vals["mask"] = f"0b{result}"
      masks.append(vals)

  with open(f"output/full.txt", "w+") as f:
    f.write(str(vals))

  print("See output for results") # add a verbose mode?


if __name__ == "__main__":
  main()