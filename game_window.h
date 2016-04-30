#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <functional>
#include <string>
#include <SFML/System/Clock.hpp>
#include "game.h"

/*!
 * \brief The game_window class, which displays the SimpleKeeper game and responds to user input
 */
class game_window
{
public:
  /*!
   * \brief game_window
   * \param window_width width width of the window in pixels
   * \param window_height height of the window in pixels
   * \param poll_time_msecs number of milliseconds the program registers and stores user input, without changing anything
   * \param stop_condition condition to terminate the game, e.g. after one seconds (useful in testing)
   * \param window_title title of the window, which is 'SimpleKeeper' by default
   */
  game_window(
    const int window_width,
    const int window_height,
    const int poll_time_msecs,
    const std::function<bool(const game_window&)> stop_condition = [](const game_window&) { return false; },
    const std::string& window_title = "SimpleKeeper"
  );
  /*!
   * \brief Run SimpleKeeper
   * May throw an exception
   */
  void execute();
  int get_total_time_msec() const noexcept { return m_start_time.getElapsedTime().asMilliseconds(); }
private:
  game m_game;
  const int m_poll_time_msecs;
  const sf::Clock m_start_time;
  const std::function<bool(const game_window&)> m_stop_condition;
  const int m_window_height;
  const std::string m_window_title;
  const int m_window_width;
};

//game_window create_defealt_game_window() noexcept;

#endif // GAME_WINDOW_H
