#include "textures.h"
#include <cassert>
#include <sstream>
#include <stdexcept>

textures::textures()
  : m_textures{}
{
  std::vector<std::pair<texture_type,std::string>> v = {
    std::make_pair(texture_type::heart_blue, "../SimpleKeeper/Sprites/TriforceGround2.png"),
    std::make_pair(texture_type::heart_red, "../SimpleKeeper/Sprites/TriforceGround1.png"),
    std::make_pair(texture_type::imp_blue_back_1, "../SimpleKeeper/Sprites/LinkBlueBack1.png"),
    std::make_pair(texture_type::imp_blue_back_2, "../SimpleKeeper/Sprites/LinkBlueBack2.png"),
    std::make_pair(texture_type::imp_blue_front_1, "../SimpleKeeper/Sprites/LinkBlueFrontSmallShield1.png"),
    std::make_pair(texture_type::imp_blue_front_2, "../SimpleKeeper/Sprites/LinkBlueFrontSmallShield2.png"),
    std::make_pair(texture_type::imp_blue_left_1, "../SimpleKeeper/Sprites/LinkBlueLeftSmallShield1.png"),
    std::make_pair(texture_type::imp_blue_left_2, "../SimpleKeeper/Sprites/LinkBlueLeftSmallShield2.png"),
    std::make_pair(texture_type::imp_blue_right_1, "../SimpleKeeper/Sprites/LinkBlueRightSmallShield1.png"),
    std::make_pair(texture_type::imp_blue_right_2, "../SimpleKeeper/Sprites/LinkBlueRightSmallShield2.png"),
    std::make_pair(texture_type::imp_red_back_1, "../SimpleKeeper/Sprites/LinkRedBack1.png"),
    std::make_pair(texture_type::imp_red_back_2, "../SimpleKeeper/Sprites/LinkRedBack2.png"),
    std::make_pair(texture_type::imp_red_front_1, "../SimpleKeeper/Sprites/LinkRedFrontSmallShield1.png"),
    std::make_pair(texture_type::imp_red_front_2, "../SimpleKeeper/Sprites/LinkRedFrontSmallShield2.png"),
    std::make_pair(texture_type::imp_red_left_1, "../SimpleKeeper/Sprites/LinkRedLeftSmallShield1.png"),
    std::make_pair(texture_type::imp_red_left_2, "../SimpleKeeper/Sprites/LinkRedLeftSmallShield2.png"),
    std::make_pair(texture_type::imp_red_right_1, "../SimpleKeeper/Sprites/LinkRedRightSmallShield1.png"),
    std::make_pair(texture_type::imp_red_right_2, "../SimpleKeeper/Sprites/LinkRedRightSmallShield2.png")
  };

  for (const auto p: v)
  {
    sf::Texture t;
    if (!t.loadFromFile(p.second))
    {
      std::stringstream msg;
      msg << __func__ << ": could not find file '"
        << p.second << "'"
      ;
      throw std::runtime_error(msg.str());
    }
    m_textures.insert(std::make_pair(p.first, t));
  }

  //Sprites from bigger picture
  {
    sf::Texture t;
    if (!t.loadFromFile("../SimpleKeeper/Sprites/DungeonsAll.png", sf::IntRect(754,858,16,16)))
    {
      std::stringstream msg;
      msg << __func__ << ": could not find file '"
        << "../SimpleKeeper/Sprites/DungeonsAll.png" << "'"
      ;
      throw std::runtime_error(msg.str());
    }
    m_textures.insert(std::make_pair(texture_type::empty, t));
  }
  {
    sf::Texture t;
    if (!t.loadFromFile("../SimpleKeeper/Sprites/DungeonsAll.png", sf::IntRect(640,697,16,16)))
    {
      assert(!"Should not get here");
    }
    m_textures.insert(std::make_pair(texture_type::floor, t));
  }
  {
    sf::Texture t;
    if (!t.loadFromFile("../SimpleKeeper/Sprites/DungeonsAll.png", sf::IntRect(280,148,16,16)))
    {
      assert(!"Should not get here");
    }
    m_textures.insert(std::make_pair(texture_type::hole, t));
  }
  {
    sf::Texture t;
    if (!t.loadFromFile("../SimpleKeeper/Sprites/DungeonsAll.png", sf::IntRect(735,887,16,16)))
    {
      assert(!"Should not get here");
    }
    m_textures.insert(std::make_pair(texture_type::wall, t));
  }
  {
    sf::Texture t;
    if (!t.loadFromFile("../SimpleKeeper/Sprites/DungeonsAll.png", sf::IntRect(261,148,16,16)))
    {
      assert(!"Should not get here");
    }
    m_textures.insert(std::make_pair(texture_type::water, t));
  }
}

const sf::Texture& textures::get(const texture_type t) const
{
  assert(m_textures.find(t) != std::end(m_textures));
  return (*m_textures.find(t)).second;
}
