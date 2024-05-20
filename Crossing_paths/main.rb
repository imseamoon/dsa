# frozen_string_literal: true

# @param {String} path
# @return {Boolean}
def is_path_crossing(path)
  x = 0
  y = 0
  visited = { [x, y] => true }

  path.each_char do |char|
    case char
    when 'N'
      y += 1
    when 'S'
      y -= 1
    when 'E'
      x += 1
    when 'W'
      x -= 1
    end

    return true if visited[[x, y]]

    visited[[x, y]] = true
  end

  false
end


# Test cases
puts is_path_crossing('NES') # false
puts is_path_crossing('NESWW') # true
